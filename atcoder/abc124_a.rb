A, B = gets.split.map(&:to_i)

puts A == B ? 2 * A : (A > B ? (2 * A - 1) : (2 * B - 1))
