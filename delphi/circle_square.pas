program CircleSquare;

{
    Вычисление площади круга по заданному радиусу R
}

const
  MY_PI = 3.14; // Константа MY_PI, её значение не может быть изменено

var
  R: Real; // Переменная для значения радиуса
  S: Real; // Площадь круга

begin
    Write('Input radius: '); // Вывод подсказки для пользователя (что вводим)
    ReadLn(R);               // Ввод с клавиатуры значения радиуса 

    S := MY_PI * R * R;      // Вычисление площади круга по известной формуле

    WriteLn('Circle square is ', S:0:2); // Вывод результата

    ReadLn; // Ожидание нажатия любой клавиши,
            // чтоб программа не завершилась раньше времени
            // и показала результат
end.
