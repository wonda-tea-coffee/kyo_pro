$c = { 0 => 0, 1 => 1, 2 => 2, 3 => 3, 4 => 2, 5 => 1, 6 => 2, 7 => 3, 8 => 4, 9 => 2 }

def roman_length(n)
  ans = 0
  while n > 0
    ans += $c[n % 10]
    n /= 10
  end
  ans
end

ans = 0
1.upto(3999) do |n|
  ans += 1 if roman_length(n) == 12
end

puts ans
