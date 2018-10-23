program SpiralMatrix;

{
  Algorithm to get quadratic matrix filled with numbers by spiral (clockwise)
}

const
  MAX = 20;

type
  Vector = array [1..MAX] of Integer;
  Matrix = array [1..MAX] of Vector;

function GetSpiralMatrix(N: Integer): Matrix;
var
  I, J, K, P: Integer;
  R: Matrix;
begin
  P := 1;

  K := 0;
  while K < N do
  begin
    // Upper row
    for J := 1 + K to N - K - 1 do
    begin
      R[K + 1][J] := P;
      P := P + 1;
    end;

    // Right column
    for I := 1 + K to N - K - 1 do
    begin
      R[I][N - K] := P;
      P := P + 1;
    end;

    // Down row
    for J := N - K downto K + 2 do
    begin
      R[N - K][J] := P;
      P := P + 1;
    end;

    // Left column
    for I := N - K downto K + 2 do
    begin
      R[I][K + 1] := P;
      P := P + 1;
    end;

    K := K + 1;
  end;
  
  if (N mod 2) = 1 then
    R[N div 2 + 1][N div 2 + 1] := P;

  Exit(R);
end;

procedure WriteMatrix(M: Matrix; N: Integer);
var
  I, J: Integer;
begin
  for I := 1 to N do
  begin
    for J := 1 to N - 1 do
      Write(M[I][J]:2, ' ');
    WriteLn(M[I][N]);
  end;
end;

var
  A: Matrix;
  N: Integer;
begin
  N := 7;
  A := GetSpiralMatrix(N);
  WriteMatrix(A, N);
end.
