program HelloWorld;

{$APPTYPE CONSOLE}

{
antilost@antilost:~/heap/delphi$ fpc hello_world.pas -orun
Free Pascal Compiler version 2.6.2-8 [2014/01/22] for x86_64
Copyright (c) 1993-2012 by Florian Klaempfl and others
Target OS: Linux for x86-64
Compiling hello_world.pas
hello_world.pas(3,2) Warning: APPTYPE is not supported by the target OS
Linking run
/usr/bin/ld.bfd: warning: link.res contains output sections; did you forget -T?
13 lines compiled, 0.0 sec 
1 warning(s) issued
antilost@antilost:~/heap/delphi$ ./run 
Hello, world!
}

begin
	WriteLn('Hello, world!');
	ReadLn;
end.
