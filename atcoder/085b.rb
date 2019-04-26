a = []
n = gets.to_i
(1..n).each { |_| a << gets.to_i }

puts a.uniq.length
