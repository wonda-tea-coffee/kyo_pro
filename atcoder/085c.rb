N, Y = gets.split.map(&:to_i)

def solve(y, n)
  return "-1 -1 -1" if y < N

  (0..n).each do |a|
    d = y - n - 9 * a
    break if d < 0

    if d % 4 == 0
      b = d / 4
      return "#{a} #{b} #{n - a - b}" if n - a - b >= 0
    end
  end

  return "-1 -1 -1"
end

puts solve(Y / 1000, N)
