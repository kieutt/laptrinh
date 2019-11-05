//Đếm số là Palindrome <=N và chia hết cho m
var n, m: longint;
    i, total: longint;
function reverse_digits(original_number:longint):longint;
var aux, reversed_number: longint;
begin
 reversed_number := 0;
 while (original_number <> 0) do
  begin
   reversed_number := reversed_number * 10 + original_number mod 10;
   original_number := original_number div 10;
  end;
  reverse_digits := reversed_number;
end;
 
function is_palindrome(number:longint):boolean;
begin
 if (number = reverse_digits(number)) then is_palindrome := true
 else is_palindrome := false;
end;
 
begin
	readln(n, m);
	total := 0;
	for i := 1 to n do 
		if (is_palindrome(i)) and (i mod m = 0) then total:=total+1;
	write(total);
end.
