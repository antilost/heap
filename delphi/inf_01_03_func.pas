program INF_01_LW_03_FUNC;
// EratosthenesSieve;

uses
  SysUtils, // Now
  Math; // Floor

{
  1. Рассказать
    - Получение случайных чисел: Random, Randomize, RandSeed
    - Пример, программа генерации вектора:
      a. const, type, NewVector, WriteVector
      b. type
      c. function NewVector(L: Integer): Vector;
      d. procedure WriteVector(V: Vector; L: Integer);
    - Указатели на функции
  2. Задачи
    - Задача 1. Генерация вектора и удаление из него всех простых чисел
      a. function IsPrimeNumberByCycle(N: Integer): Boolean;
      b. procedure RemovePrimeNumbers(var V: Vector; var L: Integer);
    - Задача 2. Проверка простых чисел с помощью решета Эратосфена 
      a. procedure InitializeSieve();
      b. function IsPrimeNumberBySieve(N: Integer): Boolean;
      c. procedure RemovePrimeNumbers(var V: Vector; var L: Integer; IsPrimeNumber: CheckNumberFunc);
    - Задача 3. Сравнить время работы алгоритмов, вынести повторяющийся код тестов в функции
      a. SysUtils и Now
      b. Число повторений >= 100
      c. Размер вектора >= 1000
      d. Инициализация "решета" 1 раз для вектора, но каждый раз на итерации повторения теста
Код основной программы (всё остальное -- в подпрограммах):
var
  Sieve: array[1 .. SIEVE_SIZE] of Boolean;
  Time: Double;
begin
  Time := MakeTest(@Test1);
  WriteLn('Test 1: ', Time:0:10);
  Time := MakeTest(@Test2);
  WriteLn('Test 2: ', Time:0:10);
  ReadLn;
end.
    
}

const
  MAX_VECTOR_SIZE = 1000;
  REPEATS_COUNT = 1000;
  SIEVE_SIZE = 1000;

type
  Vector = array[1 .. MAX_VECTOR_SIZE] of Integer;
  CheckNumberFunc = function(N: Integer): Boolean;
  TestAlgorithmFunc = procedure;

var
  Sieve: array[1 .. SIEVE_SIZE] of Boolean;
  Time: Double;


function NewVector(L: Integer): Vector;
var
  I: Integer;
begin
//  Randomize;
  RandSeed := 42;
  for I := 1 to L do
    NewVector[I] := Floor(SIEVE_SIZE * Random());
end;

procedure WriteVector(V: Vector; L: Integer);
var
  I: Integer;
begin
  for I := 1 to L - 1 do
    Write(V[I], ', ');
  WriteLn(V[L]);
end;
    


procedure InitializeSieve();
var
  I, L: Integer;
begin
  for I := 1 to SIEVE_SIZE do
    Sieve[I] := true;

  for L := 2 to SIEVE_SIZE do
  begin
    if not Sieve[L] then
      continue;
    
    I := 2 * L;
    while I <= SIEVE_SIZE do
    begin
      Sieve[I] := false;
      I := I + L;
    end;  
  end;
end;

procedure PrintSieve;
var
  I: Integer;
begin
  for I := 1 to SIEVE_SIZE do
    if Sieve[I] then
    WriteLn(I, ' ', Sieve[I]);
end;

function IsPrimeNumberByCycle(N: Integer): Boolean;
var
  I: Integer;
begin
  IsPrimeNumberByCycle := True;

  for I := 2 to Floor( Sqrt(N) ) do
    if (N mod I) = 0 then
    begin
      IsPrimeNumberByCycle := False;
      Exit;
    end;
end;

function IsPrimeNumberBySieve(N: Integer): Boolean;
begin
  IsPrimeNumberBySieve := Sieve[N];
end;

procedure RemovePrimeNumbers(var V: Vector; var L: Integer; IsPrimeNumber: CheckNumberFunc);
var
  R, W: Integer;
begin
  W := 1;
  for R := 1 to L do
  begin
    if not IsPrimeNumber(V[R]) then
    begin
      V[W] := V[R];
      W := W + 1;
    end
    else
      L := L - 1;
  end;
end;

// 
//function GetCPUTick: Int64; assembler; register;
//asm
//  RDTSC; // Read Time Stamp Counter
//  db 0fh, 31h; //rdtsc
//end;


procedure Swap(var A, B: Integer);
var
  Tmp: Integer;
begin
  Tmp := A;
  A := B;
  B := Tmp;
end;

procedure Sort1(var V: Vector; L: Integer);
var
  I, J, IMax: Integer;
begin
  for I := 1 to L do
  begin
    IMax := I;
    for J := I + 1 to L do
      if V[J] > V[IMax] then
        IMax := J;
    if I <> J then
      Swap(V[I], V[J]);
  end;
end;

procedure Test1;
var
  A: Vector;
  N: Integer;
  I: Int64;
begin
  for I := 1 to REPEATS_COUNT do
  begin
    N := MAX_VECTOR_SIZE;
    A := NewVector(N);
    RemovePrimeNumbers(A, N, @IsPrimeNumberByCycle);
  end;
end;

procedure Test2;
var
  A: Vector;
  N: Integer;
  I: Int64;
begin
  InitializeSieve();
  for I := 1 to REPEATS_COUNT do
  begin
    N := MAX_VECTOR_SIZE;
    A := NewVector(N);
    RemovePrimeNumbers(A, N, @IsPrimeNumberBySieve);
  end;
end;

function MakeTest(Test: TestAlgorithmFunc): Double;
var
  T0, T1: TDateTime;
begin
  T0 := Now();
  Test();
  T1 := Now();

  MakeTest := T1 - T0;
end;




begin
  Time := MakeTest(@Test1);
  WriteLn('Test 1: ', Time:0:10);

  Time := MakeTest(@Test2);
  WriteLn('Test 2: ', Time:0:10);

//  ReadLn;
end.
