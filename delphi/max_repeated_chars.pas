program MaxRepeatedChars;

{
    Найти максимальное количество подряд идущих одинаковых символов в последовательности
}

var
  N, C, Max, I: Integer;
  L, Prev: Char;
begin
  ReadLn(N);
  Max := -1;

  ReadLn(L);
  Prev := L;
  C := 1;
  Max := C;

  for I := 2 to N do
  begin
    ReadLn(L);

    if L = Prev then
    begin
      Inc(C);
      
      if C > Max then
      begin
        Max := C;
      end;
    end
    else
      C := 1;

    Prev := L;
  end;

  WriteLn(Max);
end.
