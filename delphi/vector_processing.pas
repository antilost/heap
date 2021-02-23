program VectorProcessing;

const
  N_MAX = 20;

type
  Vector = array [1..N_MAX] of Integer;

procedure InputVector(var V: Vector; var N: Integer);
var
  I: Integer;
begin
  repeat
    Write('N = ');
    ReadLn(N);
  until (N >= 1) and (N <= N_MAX);
  for I := 1 to N do
    Read(V[I]);
  ReadLn;
end;

procedure RandomVector(var V: Vector; var N: Integer);
var
  I: Integer;
begin
  repeat
    Write('N = ');
    ReadLn(N);
  until (N >= 1) and (N <= N_MAX);
  for I := 1 to N do
    V[I] := Random(100); // 0 .. 100
end;

procedure WriteVector(const V: Vector; const N: Integer);
var
  I: Integer;
begin
  if N = 0 then
  begin
    WriteLn('Vector is empty');
    Exit;
  end;

  for I := 1 to N - 1 do
    Write(V[I], ', ');
  WriteLn(V[N]);
end;

procedure DeleteMaxNumber(var V: Vector; var N: Integer);
var
  I, MaxI: Integer;
begin
  if N = 0 then
    Exit;
  MaxI := 1;
  for I := 2 to N do
    if V[I] > V[MaxI] then
      MaxI := I;
  for I := MaxI to N - 1 do
    V[I] := V[I + 1];
  N := N - 1;
end;

function IndexOfMinNumber(const V: Vector; const N: Integer; const Left: Integer; const Right: Integer): Integer;
var
  I, MinI: Integer;
begin
  MinI := 0;
  for I := Left to Right do
  begin
    if (MinI < 1) or (V[I] < V[MinI]) then
      MinI := I;
  end;
  Exit(MinI);
end;

procedure SortVector(var V: Vector; var N: Integer);
var
  I, MinI, Tmp: Integer;
begin
  for I := 1 to N do
  begin
    MinI := IndexOfMinNumber(V, N, I, N);
    Tmp := V[MinI];
    V[MinI] := V[I];
    V[I] := Tmp;
  end
end;

var
  S: Integer;
  M: Vector;
  Length: Integer;
begin
  Length := 0;
  while True do
  begin
    WriteLn('1. Input array');
    WriteLn('2. Generate random array');
    WriteLn('3. Delete maximum');
    WriteLn('4. Sort array');
    WriteLn('0. Exit');
    Write('> ');
    ReadLn(S);

    case S of
      1: InputVector(M, Length);
      2: RandomVector(M, Length);
      3: DeleteMaxNumber(M, Length);
      4: SortVector(M, Length);
      0: break;
    end;

    WriteVector(M, Length);
    WriteLn;
  end
end.