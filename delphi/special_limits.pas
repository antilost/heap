program Limits;

uses
    Math;

const
  EPS = 1e-6;

var
  X, L, Expp: Real;
  N: Integer;
begin

  // Первый замечательный предел
  // lim x -> 0 ( sin(x)/x )
  X := 1;
  repeat
    L := Sin(X) / X;
    X := X / 2;
  until Abs(X) < EPS;
  WriteLn('    x = ', X:0:8);
  WriteLn('FSL l = ', L:0:8);

  // Второй замечательный предел
  // lim n -> INF (1 + 1/n) ^ n
  Expp := Exp(1);
  N := 1;
  repeat
    if N = High(N) then
      break;
    L := Power(1 + 1 / N, N);
    Inc(N);
  until (N <= High(N)) and (Abs(L - Expp) < EPS);
  WriteLn('    n = ', N);
  WriteLn('SSL l = ', L:0:12);

  
  ReadLn;
end.
