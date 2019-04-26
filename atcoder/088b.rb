N = gets.to_i
an = gets.split.map(&:to_i).sort.reverse

alices_score = 0
bobs_score = 0

an.each_with_index { |a, index|
  if index % 2 == 0
    alices_score += a
  else
    bobs_score += a
  end
}

puts alices_score - bobs_score
