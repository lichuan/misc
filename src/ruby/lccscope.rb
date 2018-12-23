#!/usr/bin/env ruby
# -*- coding: utf-8 -*-

FILE_LIST = [
             [".", ["3rd-party", "build"]]
            ]

$cscope_file_list = []

def exclude? path, arr
  arr[1].each do |file|
    return true if arr[0] + "/" + file == path
  end  
  false
end

def consider? path
  [".h", ".hpp", ".hxx", ".c", ".cc", ".inl", ".cxx", ".cpp"].each {|suffix| return true if path.end_with? suffix}
  false
end

def gen_cscope path, arr
  return if not Dir.exist? path  
  Dir.foreach path do |f|
    next if f == "." or f == ".."
    next_path = path + "/" + f
    next if exclude? next_path, arr
    if File.directory? next_path
      gen_cscope next_path, arr
    elsif consider? next_path
      if File.symlink? next_path
        dir_part = File.split(next_path)[0]
        link_path = File.readlink next_path
        cnt = 0
        while true do
          md = /(\.\.\/)(.*)/.match link_path
          break if md.nil?
          cnt += 1
          link_path = md[2]
        end
        while cnt > 0 do
          dir_part = File.split(dir_part)[0]
          cnt -= 1
        end
        next_path = dir_part + "/" + link_path
      end
      $cscope_file_list.push next_path
    end
  end
end

FILE_LIST.each do |arr|
  gen_cscope arr[0], arr
end

fp = File.open("cscope.files", "w")
fp.write($cscope_file_list.join("\n") + "\n")
fp.close
system("cscope -b -i cscope.files -f cscope.out")
