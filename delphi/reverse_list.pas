program ReverseList;

uses
  SysUtils;

type
  List = ^Node;
  Node = record
    Value: Integer;
    Next: List;
  end;



procedure RecursiveReverseIteration(Prev: List; var OriginalHead, Current: List);
begin
  if Current = nil then
  begin
    OriginalHead := Prev;
  end
  else
  begin
    RecursiveReverseIteration(Current, OriginalHead, Current.Next);
    Current.Next := Prev;
  end;
end;


procedure RecursiveReverse(var Head: List);
var
  CopyHead: List;
begin
  CopyHead := Head;
  RecursiveReverseIteration(nil, Head, CopyHead);
end;


procedure Reverse(var Head: List);
var
  Tmp, Prev: List;
begin
  Prev := nil;
  while Head <> nil do
  begin
    Tmp := Head.Next;
    Head.Next := Prev;
    Prev := Head;
    Head := Tmp;
  end;
  Head := Prev;
end;

procedure Push(var Head: List; Val: Integer);
var
  NewNode: List;
begin
  New(NewNode);
  NewNode.Value := Val;
  NewNode.Next := Head;
  Head := NewNode;  
end;

procedure Print(Head: List);
var
  I: List;
begin
  I := Head;
  while I <> nil do
  begin
    Write(I.Value);
    if I.Next <> nil then
      Write(' -> ');
    I := I.Next;
  end;
  WriteLn;
end;

var
  Head: List;
begin
  Head := nil;
  Push(Head, 1);
  Print(Head);

  Push(Head, 4);
  Print(Head);

  Push(Head, 3);
  Print(Head);

  Push(Head, 5);
  Print(Head);

  Reverse(Head);
  Print(Head);

  RecursiveReverse(Head);
  Print(Head);

  RecursiveReverse(Head);
  Print(Head);
end.
