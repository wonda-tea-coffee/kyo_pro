$depth_search_cnt = 0
$m = 3000
$n = 2500

def depth_search(n)
  $depth_search_cnt += 1
  puts "#{$depth_search_cnt}: #{n}" || exit if $depth_search_cnt == $n

  depth_search(n * 2) if n * 2 <= $m
  depth_search(n + 1) if n + 1 <= $m && n % 2 == 0
end

depth_search(1)
