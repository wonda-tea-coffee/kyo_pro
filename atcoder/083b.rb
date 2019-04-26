def digits_sum(n)
  ans = 0
  while n > 0 do
    ans += n % 10
    n /= 10
  end
  ans
end

N, A, B = gets.split.map(&:to_i)

ans = 0
(1..N).each do |n|
  d = digits_sum(n)
  ans += n if A <= d && d <= B
end

puts ans
