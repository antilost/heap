program OperatorCaseWithoutSubProgram;

{
    Задать массив случайных чисел.
    Вывести массив на экран.
    Вычислить сумму всех нечётных элементов и удалить их.
}

const
  MAX = 10;

type
  Vector = array[1 .. MAX] of Integer;

var
  N, I, R, W, Sum: Integer;
  A: Vector; // Вектор -- одномерный массив
begin
  N := MAX;

  // Задать массив псевдо-случайных чисел.
  Randomize();
  RandSeed := 10;
  for I := 1 to N do
    A[I] := 1 + Random(10);

  // Вывести массив на экран.
  for I := 1 to N - 1 do
    Write(A[I], ' ');
  WriteLn(A[N]);

  // Вычислить сумму всех нечётных элементов и удалить их
  Sum := 0;
  W := 1;
  for R := 1 to N do
    case A[R] mod 2 of
      0:
      begin
        A[W] := A[R];
        W := W + 1;
      end;
      1:
        Sum := Sum + A[R];
    end;
  N := W - 1;

  WriteLn('Sum is ', Sum);

  // Вывести массив на экран.
  for I := 1 to N - 1 do
    Write(A[I], ' ');
  WriteLn(A[N]);
end.
