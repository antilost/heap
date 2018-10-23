program FindBestMarkStudent;

type
  TStudent = record
    Name: String[20];
    Mark: Integer;
  end;

const
  N = 4;

var
  S: array [1 .. N] of TStudent;
  BestStudent: TStudent;
  I: Integer;
begin
  with S[1] do
  begin
    Name := 'John';
    Mark := 5;
  end;
  
  S[2].Name := 'Alice';
  S[2].Mark := 4;

  S[3].Name := 'Gerald';
  S[3].Mark := 5;

  S[4].Name := 'Charlie';
  S[4].Mark := 3;

  BestStudent := S[1];
  for I := 2 to N do
    if S[I].Mark >= BestStudent.Mark then
      BestStudent := S[I];

  WriteLn(BestStudent.Name);
  //ReadLn;
end.
