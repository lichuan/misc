set fso=createobject("scripting.filesystemobject") 
Dim file_path
file_path = WScript.Arguments(0)
set file=fso.opentextfile(file_path)

do while file.atendofstream<>true 
a=file.readline
s = Instr(1,a, "FileVersion") 
if s<>0 then
set fi=fso.opentextfile(file_path) 
d=fi.readall 
fi.close  
set f=fso.opentextfile(file_path, 2) 
f.write  Replace(d,a,WScript.Arguments(1))
f.close  
end if
loop  
file.close