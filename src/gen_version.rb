#!/usr/bin/env ruby

require 'yaml'
require 'digest/md5'

WORK_DIR = "D:/repos/gobang/resource"
VERSION_DIR = "#{WORK_DIR}/version_history"

$md5_dict_before = {}
$md5_dict_change = {}
$md5_dict_all = {}

def read_md5_from_history
  md5_dict = {}
  Dir.foreach VERSION_DIR do |f|
    next if f == "." or f == ".."
    path = VERSION_DIR + "/" + f
    md5_dict[f] = YAML.load(File.open(path))
  end
  
  md5_arr = md5_dict.sort
  md5_arr.each do |v|
    v[1].each {|file, md5val| $md5_dict_before[file] = md5val}
  end
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
      md5val = Digest::MD5.hexdigest(File.read new_path)
      $md5_dict_all[new_file_name] = md5val
      if not $md5_dict_before.has_key? new_file_name or $md5_dict_before[new_file_name] != md5val
        $md5_dict_change[new_file_name] = md5val
      end
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
  open(VERSION_DIR + "/#{new_version}", "w") {|f| YAML::dump $md5_dict_change, f}
  open(cur_version_path, "w") {|f| YAML::dump({"version" => new_version}, f)}
  open(file_version_path, "w") {|f| YAML::dump $md5_dict_all, f}
end

def main()
  read_md5_from_history
  update_new_version
end

main
