unit ArrayUtils;

interface

const
PI = 3.1;

type
  TArray = array of Integer;

function GenerateArray(const A, B, N: Integer): TArray;
procedure WriteArray(const A: TArray);

implementation

function GenerateArray(const A, B, N: Integer): TArray;
var
  I, P: Integer;
begin
  SetLength(Result, N);
  for I := 1 to Length(Result) do
  begin
    P := Random(B - A + 1) + A;
    Result[I] := P;
  end;
end;

procedure WriteArray(const A: TArray);
var
  I: Integer;
begin
  for I := 1 to Length(A) do
    Write(A[I], ' ');
  WriteLn;
end;


end.