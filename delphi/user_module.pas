program UserModule;

uses
  ArrayUtils;

var
  B: TArray;
begin
  WriteArray(B);
  B := GenerateArray(1, 4, 10); // массив из 10 чисел, каждое от 1 до 4
  WriteArray(B);
end.
