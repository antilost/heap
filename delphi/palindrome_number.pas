program Pal;
var
  A, Result: Integer;
  DT, T, S, D, E: Integer;
begin
  ReadLn(A);
  DT := A div 10000;
  A := A - DT * 10000;

  T := A div 1000;
  A := A - T * 1000;

  S := A div 100;
  A := A - S * 100;

  D := A div 10;
  A := A - D * 10;
  
  E := A;
  
  WriteLn(DT);
  WriteLn(T);
  WriteLn(S);
  WriteLn(D);
  WriteLn(E);

  Result := (DT - E) + (T - D);
  WriteLn('Is palindrome: ', Result);
  ReadLn;
end.
