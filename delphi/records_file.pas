program RecordsFile;

uses
  SysUtils;

// Используемые в программе типы пользователя
type
  // Описание типа записи "Студент"
  TStudent = record
    Name: String[20];    // Имя
    Math, Physics: Byte; // Оценка по математике и по физике
  end;
  
  // Описание типа файловой переменной для работы с типизированным файлом,
  // состоящим из записей TStudent
  TFile = File of TStudent;


// Процедура для сохранения в файл новых записей
// Использует файловую переменную F, которая до вызова процедуры
// должна быть связана с именем файла (AssignFile)
procedure WriteFile(var F: TFile);
var
  N, I: Integer;
  S: TStudent;
begin
  Write('Enter records count: ');
  ReadLn(N);

  ReWrite(F); // Открытие файла для перезаписи или создание нового файла
  
  // Ввод N записей и добавление каждой в файл
  for I := 1 to N do
  begin
    // Вводим данные переменной-записи S
    WriteLn('Record #', I);
    Write('Enter student name: ');
    ReadLn(S.Name);
    Write('Math: ');
    ReadLn(S.Math);
    Write('Physics: ');
    ReadLn(S.Physics);
    
    // Добавляем S в конец файла F
    Write(F, S);
  end;
  
  // TODO
  // Здесь чего-то не хватает: добавьте!
end;


// Процедура для считывания данных из существующего файла
procedure ReadFile(var F: TFile);
var
  Buffer: TStudent;
begin
  // TODO
  // Добавить проверку существования файла

  Reset(F); // Установить указатель чтения-записи в начало файла
  
  // EOF(F) возвращает true только тогда, когда достигнут конец файла
  while not EOF(F) do
  begin
    // Считываем из файла очередную компоненту-запись в переменную Buffer
    Read(F, Buffer);
    
    // Вывод одной записи в формате 'Student Ivanov: 4, 5'
    WriteLn('Student ', Buffer.Name, ': ', Buffer.Math, ', ', Buffer.Physics);
  end;
  WriteLn;
  Close(F); //CloseFile(F);
end;


// Основная программа
var
  F: TFile;
  Selected: Integer;
begin
  // TODO
  // Имя файла задано явно, добавьте возможность ввода с клавиутура,
  // чтобы от запуска к запуску программа могла обрабатывать разные файлы
  Assign(F, 'rkt.dat'); // Assign(F, 'rkt.dat');
  
  while True do
  begin
    WriteLn('Select action:');
    WriteLn('1) Write new file');
    WriteLn('2) Show file content');
    // TODO
    // Добавьте описание новых процедур по заданию
    WriteLn('0) Exit');
    
    ReadLn(Selected);
    
    case Selected of
        1: WriteFile(F);
        2: ReadFile(F);
        0: break; // Завершение цикла и выход из программы
    end;
  end;
end.
