require './math'

R = 8

def digits_sum(n)
  e = n.to_s.length
  ans = 0
  while n > 0
    ans += (n % 10) ** e
    n /= 10
  end
  ans
end

n = 8
cnt = 0
while true
  n8 = rad(n, 10, R).to_i
  if digits_sum(n8) == n
    cnt += 1
    puts "#{cnt}: #{n8}"
    break if cnt == 8
  end
  n += 1
end
