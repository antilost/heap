program SquareEquation;

{
    Решение квадратного уравнения по заданным коэффициентам A, B, C
}

var
  A, B, C, D, X1, X2: Real;
begin
  WriteLn('Введите значения коэффициентов');
  Write('A: '); ReadLn(A);
  
  if A = 0 then
  begin
    // Код внутри данного блока begin-end
    // будет выполнен только если A = 0
    WriteLn('A = 0');
    ReadLn;
    Exit; // Команда выхода из программы
  end;
  
  Write('B: '); ReadLn(B);
  Write('C: '); ReadLn(C);

  D := Sqr(B) - 4 * A * C; // Вычисление дискриминанта

  if D < 0 then
  begin
    // Этот код выполнится только если дискриминант будет меньше нуля
    WriteLn('Корни мнимые');
  end
  else
  begin
    // Этот блок выполнится если дискриминант не меньше 0 (больше, либо равен)
    if D = 0 then
    begin
      X1 := -B / (2 * A);
      WriteLn('Один корень, X = ', X1:0:2);
    end
    else
    begin
      X1 := (-B + Sqrt(D)) / 2 / A;
      X2 := (-B - Sqrt(D)) / 2 / A;
      WriteLn('X1 = ', X1:0:2, ', X2 = ', X2:0:2);
    end;
  end;

  ReadLn;
end.
