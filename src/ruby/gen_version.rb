#!/usr/bin/env ruby

require 'yaml'
require 'digest/md5'

REPOS_DIR = "D:/repos/gobang"
WORK_DIR = "#{REPOS_DIR}/resource"
VERSION_DIR = "#{WORK_DIR}/version_history"

$md5_dict_history = {}
$md5_dict_change = {}
$md5_dict_all = {}
$md5_dict_del = {}

def del_from_history
  md5_dict = {}
  Dir.foreach VERSION_DIR do |f|
    next if f == "." or f == ".."
    path = VERSION_DIR + "/" + f
    fd = File.open(path)
    id = f.to_i
    md5_dict[id] = YAML.load(fd)
    fd.close
    $md5_dict_del.each_key do |key|
      md5_dict[id].delete key      
    end    
    open(path, "w") {|f| YAML::dump md5_dict[id], f}
  end
end

def read_md5_from_history
  Dir.mkdir VERSION_DIR if not File.directory? VERSION_DIR
  md5_dict = {}
  Dir.foreach VERSION_DIR do |f|
    next if f == "." or f == ".."
    path = VERSION_DIR + "/" + f
    md5_dict[f.to_i] = YAML.load(File.open(path))
  end
  
  md5_arr = md5_dict.sort
  md5_arr.each do |v|
    v[1].each {|file, md5val| $md5_dict_history[file] = md5val}
  end
  $md5_dict_del = $md5_dict_history.clone
end

def do_md5_file(path, file_name)
  Dir.foreach path do |f|
    next if f == "." or f == ".." or f == ".svn"
    new_path = path + "/" + f
    new_file_name = file_name
    if file_name.empty?
      new_file_name = f
    else
      new_file_name += "/" + f
    end
    if File.directory? new_path
      next if f == "version_history"
      do_md5_file(new_path, new_file_name)
    else
      next if f == "gen_version.rb" or f == "file_version.yaml" or f == "cur_version.yaml"
      md5val = Digest::MD5.hexdigest(File.binread new_path)
      $md5_dict_all[new_file_name] = md5val
      if not $md5_dict_history.has_key? new_file_name or $md5_dict_history[new_file_name] != md5val
        $md5_dict_change[new_file_name] = md5val
      end
      $md5_dict_del.delete new_file_name
    end
  end
end

def update_new_version
  new_version = 1
  cur_version_path = WORK_DIR + "/cur_version.yaml"
  file_version_path = WORK_DIR + "/file_version.yaml"
  if File.exist? cur_version_path
    new_version = YAML.load(File.open(cur_version_path))["version"] + 1
  end
  do_md5_file WORK_DIR, ""
  del_from_history if not $md5_dict_del.empty?
  return if $md5_dict_change.empty?  
  open(VERSION_DIR + "/#{new_version}", "w") {|f| YAML::dump $md5_dict_change, f}
  open(cur_version_path, "w") {|f| YAML::dump({"version" => new_version, "update_all" => 0}, f)}
  open(file_version_path, "w") {|f| YAML::dump $md5_dict_all, f}
end

def main()
  system("lcbuild-dos")
  read_md5_from_history
  update_new_version
end

main
