#!/usr/bin/env ruby

require 'digest/md5'

REPOS_DIR = "D:/repos/gobang"

def transform(dir_path)
  Dir.foreach dir_path do |f|
    next if f == "." or f == ".." or f == ".git" or f == ".gitignore" or f == "cocos2d" or f == "transform.rb"
    cur_path = dir_path + "/" + f
    if File.directory? cur_path
      transform cur_path
    else
      next if %w[.h .hpp .cc .xml .cpp .cxx .lua .rb .proto .yaml].none? {|suffix| f.end_with? suffix}
      md5val = Digest::MD5.hexdigest("test")
      idx = 0
      fd = File.new cur_path, "rb"
      xor_arr = []
      fd.each_byte do |c|
        xor_c = (c ^ md5val[idx].ord)
        idx += 1
        idx = 0 if idx == 32
        xor_arr << xor_c
      end
      fd.close
      fd = File.new cur_path, "wb"
      xor_arr.each do |c|
        fd.putc c
      end
      fd.close
    end
  end
end

def main()
  transform REPOS_DIR
end

main
