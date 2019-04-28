N = gets.to_i
hn = gets.split.map(&:to_i)

max = 0
cnt = 0
(0..(N-1)).each do |i|
  cnt += 1 if hn[i] >= max
  max = [max, hn[i]].max
end

puts cnt
