program QuickSort;

type
  TArray = array of Integer;

function Partition(var A: TArray; P, R: Integer): Integer;
var
  X, I, J, Tmp: Integer;
begin
  X := A[P];
  I := P - 1;
  J := R + 1;
  while True do
  begin
    repeat
      J := J - 1;
    until A[J] <= X;

    repeat
      I := I + 1;
    until A[I] >= X;

    if I < J then
    begin
      Tmp := A[I];
      A[I] := A[J];
      A[J] := Tmp;
    end
    else
      Exit(J);
  end;
end;

procedure Sort(var A: TArray; P, R: Integer);
var
  Q: Integer;
begin
  if P < R then
  begin
    Q := Partition(A, P, R);
    Sort(A, P, Q);
    Sort(A, Q + 1, R);
  end;
end;

var
  B: TArray;
  I: Integer;
begin
  Randomize;
  SetLength(B, 20);
  for I := 0 to Length(B) - 1 do
    B[I] := 10 + Random(90);
  for I := 0 to Length(B) - 1 do
    Write(B[I], ' ');
  WriteLn;
  Sort(B, 0, Length(B) - 1);
  for I := 0 to Length(B) - 1 do
    Write(B[I], ' ');
  WriteLn;
end.
