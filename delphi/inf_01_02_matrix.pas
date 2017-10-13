program INF_01_LW_02_MATRIX;

type
  TMatrix = array[1..10, 1..10] of Integer;

procedure ShowMatrix(A: TMatrix; M, N: Integer);
var
  I, J: Integer;
begin
  for I := 1 to M do
  begin
    for J := 1 to N - 1 do
      Write(A[I, J], ' ');
    WriteLn(A[I, N]);
  end;
end;

function FibonacciMatrix(N: Integer): TMatrix;
var
  I, J: Integer;
  FPrev, FPrevPrev: Integer;
begin
  FPrev := 0;
  FPrevPrev := 1;
  for I := 1 to N do
    for J := 1 to N do
    begin
      FibonacciMatrix[I, J] := FPrev + FPrevPrev;
      FPrevPrev := FPrev;
      FPrev := FibonacciMatrix[I, J];
    end;
end;

procedure OneZeroMatrix(var G: TMatrix; M, N: Integer);
var
  I, J: Integer;
  NumberToFill: Integer;
begin
  NumberToFill := 1;
  if M > N then
    NumberToFill := 0;
  for I := 1 to M do
    for J := 1 to N do
    begin
      G[I, J] := NumberToFill;
      NumberToFill := (NumberToFill + 1) mod 2;
    end;
end;

procedure FirstOddNumbersByColumns(var G: TMatrix; M, N: Integer);
var
  I, J: Integer;
  NumberToFill: Integer;
begin
  NumberToFill := 1;
  for J := 1 to N do
    for I := 1 to M do
    begin
      G[I, J] := NumberToFill;
      NumberToFill := NumberToFill + 2;
    end;
end;

procedure FirstEvenNumbersByColumns(var G: TMatrix; M, N: Integer);
var
  I, J: Integer;
  NumberToFill: Integer;
begin
  NumberToFill := 2;
  for J := 1 to N do
    for I := M downto 1 do
    begin
      G[I, J] := NumberToFill;
      NumberToFill := NumberToFill + 2;
    end;
end;

procedure SuperDiagonalMatrix(var G: TMatrix; M, N: Integer);
var
  I, J: Integer;
begin
  for I := 1 to M do
    for J := 1 to N do
      if I > J then
        G[I, J] := 0
      else
        G[I, J] := 1;
end;

procedure SubDiagonalMatrix(var G: TMatrix; M, N: Integer);
var
  I, J: Integer;
begin
  for I := 1 to M do
    for J := 1 to N do
      if I >= J then
        G[I, J] := 1
      else
        G[I, J] := 0;
end;

procedure SqrByRowsMatrix(var G: TMatrix; M, N: Integer);
var
  I, J, K: Integer;
begin
  K := 1;
  for I := 1 to M do
    for J := N downto 1 do
    begin
      G[I, J] := Sqr(K);
      Inc(K);
    end;
end;



var
  A: TMatrix;
  M, N: Integer;
begin
  N := 4; A := FibonacciMatrix(N); ShowMatrix(A, N, N); WriteLn;

  M := 2; N := 7; OneZeroMatrix(A, M, N); ShowMatrix(A, M, N); WriteLn;
  M := 4; N := 3; OneZeroMatrix(A, M, N); ShowMatrix(A, M, N); WriteLn;

  M := 3; N := 4; FirstOddNumbersByColumns(A, M, N); ShowMatrix(A, M, N); WriteLn;
  
  M := 3; N := 4; FirstEvenNumbersByColumns(A, M, N); ShowMatrix(A, M, N); WriteLn;

  M := 3; N := M; SuperDiagonalMatrix(A, M, N); ShowMatrix(A, M, N); WriteLn;

  M := 3; N := M; SubDiagonalMatrix(A, M, N); ShowMatrix(A, M, N); WriteLn;
  
  M := 3; N := 4; SqrByRowsMatrix(A, M, N); ShowMatrix(A, M, N); WriteLn;
  //ReadLn;    
end.