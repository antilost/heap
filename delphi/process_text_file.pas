program CreateAndReadTextFile;

var
  T: TextFile; // Переменная-дескриптор текстового файла
  I: Integer;
  M: Real;
  S: String;
begin
  AssignFile(T, 'my_data.txt'); // Связь файловой переменной с именем файла на диске

  ReWrite(T); // Открытие файла для перезаписи (создания)
  WriteLn(T, 'Hello, world!'); // Запись в файл одной строки символов "Hello, world!"
  for I := 1 to 5 do // Вычисление m = $0.1 i^2$ и запись значения в файл для i = 1,2,3,4,5
  begin
    M := 0.1 * Sqr(I);
    WriteLn(T, M:0:2);
  end;
  Write(T, 42);  // Запись числа 42 без перевода строки
  Write(T, ';'); // Запись символа ; сразу за числом 42
  S := 'See ya!';
  WriteLn(T, S); // Запись содержимого строки S
  CloseFile(T);  // Закрытие файла для завершения работы и сохранения результатов на жесткий диск
  
  Reset(T);       // Открытие текстового файла для чтения
  while not EOF(T) do
  begin
    ReadLn(T, S); // Считываем из файла очередную строку в переменную S
    WriteLn(S);   // Вывод значения строки S на экран (в консоль)
  end;
  CloseFile(T);  // Закрытие файла

  ReadLn;
end.
