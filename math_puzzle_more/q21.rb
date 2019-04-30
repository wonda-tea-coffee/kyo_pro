# s = Time.now

# PAGE, DAYS = 140, 18
# @memo = {}

# 本のページ数を100ページとする
# これを day 日で読める最小のページ数は、
# 1 + 2 + ... + day = day * (day + 1) / 2

# # page ページの本を day 日で読むパターンの総数を求める
# def solve2(page, day)
#   return @memo[[page, day]] if @memo[[page, day]]
#   return 1 if day == 1
#   return 0 if page < day * (day + 1) / 2

#   ans = 0

#   hoge{
#     ans += solve2(n - i, day - 1)
#   }

#   @memo[[page, day]] = ans
# end

# ans = 0
# # nページの本をm日以内に読むパターンの総数を求める
# 1.upto(m){|i| ans += solve2(n, i) }

# puts ans
# puts "#{Time.now - s}s"

PAGES, DAYS = 100, 2

@memo = {}
def search(page, days)
  return @memo[[page, days]] if @memo[[page, days]]

  return 1 if days == 1
  cnt = 0

  (page - days * (days - 1) / 2) / days

  # (残りページ) - [days-1]日で読める最小のページ

  puts "1 ~ #{(page - days * (days - 1) / 2) / days}"
  1.upto((page - days * (days - 1) / 2) / days) do |i|
    s = search(page - i * days, days - 1)
    # i =  1: search(98, 1)
    # i =  2: search(96, 1)
    # ~
    # i = 49: search( 2, 1)
    puts "  search(#{page - i * days}, #{days - 1}) = #{s}"
    cnt += s
  end
  @memo[[page, days]] = cnt
end

cnt = 0
1.upto(DAYS) do |i|
  cnt += search(PAGES, i)
end

puts cnt
