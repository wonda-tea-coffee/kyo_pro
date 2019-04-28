n = 100
@memo = Array.new(n + 1){Array.new(n + 1)}

def solve(n, m, log)
  return @memo[n][m] if @memo[n][m]

  if n == 0
    puts log.slice(3..log.length)
    return @memo[n][m] = 1
  end

  ans = 0
  (m..[n, 10].min).each { |i|
    ans += solve(n - i, i, log + " + #{i}")
  }
  @memo[n][m] = ans
end

puts solve(n, 2, "")
