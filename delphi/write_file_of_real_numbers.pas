program WriteFileOfRealNumbers;
uses SysUtils;
type
  FR = File of Real;

procedure ShowFile(var F: FR);
var
  P: Real;
begin
  Reset(F);
  while not EOF(F) do
  begin
    Read(F, P);
    Write(P:0:1, ' ');
  end;
  WriteLn;
  CloseFile(F);
end;

var
  F: File of Real;
  N, I: Integer;
  P, Sum, Avg: Real;
begin
  AssignFile(F, 'numbers.dat');
  ReWrite(F);
  N := 10;
  for I := 1 to N do
  begin
    P := Random(10)/10; // вещ. число от 0 до 9 деленное на 10
    Write(F, P);
  end;
  CloseFile(F);

  ShowFile(F);
  
  Sum := 0;
  Reset(F);
  while not EOF(F) do
  begin
    Read(F, P);
    Sum := Sum + P;
  end;
  WriteLn('Sum = ', Sum:0:6);
  Avg := Sum / FileSize(F);
  WriteLn('Avg = ', Avg:0:6);
  CloseFile(F);

  Reset(F);
  for I := FileSize(F) - 1 downto 1 do
  begin
    Seek(F, I);
    Read(F, P);
    Write(F, P);
  end;
  Reset(F);
  Write(F, Sum);
  CloseFile(F);

  ShowFile(F);
  
  WriteLn('SizeOf Real: ', SizeOf(Real));
  WriteLn('SizeOf F: ', SizeOf(F));
  WriteLn('SizeOf P: ', SizeOf(P));
  Reset(F);
  WriteLn('FileSize: ', FileSize(F));
  WriteLn('SizeOf F / FileSize: ', SizeOf(F) / FileSize(F));
  
end.