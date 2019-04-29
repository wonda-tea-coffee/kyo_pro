# ・ヒューリスティックで全種類使えるパターンを確認する
# ・全部使うことは確定、それを前提に探索

$target = 45678

# 45678

# 45678
#   5678(4)
#     678(1)
#   15678(3)
#     678(3)
#     5678(2)
#       1678(2)
#         678(1)
#           178(1)
#             78(1)
#               28(1)
#                 8(2)
#                   3(1)
#                     0(3)

$moneys = [10000, 5000, 2000, 1000, 500, 100, 50, 10, 5, 1]
$len = $moneys.length

# 前提：$targetに全パターンの硬貨・紙幣で作れる組み合わせが存在すること
def solve(index, remain, cnt, log)
  if index == $len
    puts cnt
    puts log[2..log.length]
    exit
  end

  money = $moneys[index]
  lim = remain / money

  return false if lim == 0

  lim.downto(1){|i|
    return true if solve(index + 1, remain - money * i, cnt + i, log + " + #{money} * #{i}")
  }

  return false
end

solve(0, $target, 0, "")
