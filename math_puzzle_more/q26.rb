s = Time.now

N = 24
A = 10
B = 10
S = A + B
@memo = {}

def f(n, a)
  return @memo[[n, a]] if @memo[[n, a]]
  return a == A ? 1 : 0 if n == 0

  ans = f(n - 1, a) # あいこ
  ans += f(n - 1, a - 1) if a > 1
  ans += f(n - 1, a + 1) if S - a > 1

  @memo[[n, a]] = ans
end

puts f(N, A + B) + f(N, 0)
puts "#{Time.now - s}s"
