N = gets.to_i

tn = []
xn = []
yn = []

N.times {
  t, x, y = gets.split.map(&:to_i)
  tn << t
  xn << x
  yn << y
}

t_prev = 0
x_prev = 0
y_prev = 0
(0..(N-1)).each { |i|
  t_next = tn[i]
  x_next = xn[i]
  y_next = yn[i]

  # 次の地点までの距離
  d = (x_next - x_prev).abs + (y_next - y_prev).abs

  # 移動に使える時間
  t = t_next - t_prev

  # 時間が足りないか、時間ちょうどにたどり着けない場合はアウト
  if t < d || (t - d) % 2 == 1
    puts "No"
    exit
  end

  t_prev = t_next
  x_prev = x_next
  y_prev = y_next
}

puts "Yes"
