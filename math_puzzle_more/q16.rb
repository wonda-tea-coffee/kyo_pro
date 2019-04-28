start_time = Time.now

def gcd(a, b)
  return 1 if b == 1
  return b if a % b == 0

  return gcd(b, a % b)
end

n = 1234567
ans = 0

start_a = (n + 1) / 2
lim_a = n - 1
ans = 0

start_a.upto(lim_a) {|a|
  b = n - a
  ans += 1 if gcd(a, b) == 1
}

puts ans

puts "#{Time.now - start_time}s"
