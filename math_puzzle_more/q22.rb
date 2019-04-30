SIZE = 10

def solve(map)
  mins = Array.new(SIZE){Array.new(SIZE, -1)}

  queue = []
  queue << [0, 0, map[0][0]]

  while queue.length > 0
    x, y, cost = queue.shift

    next if mins[y][x] != -1 && mins[y][x] < cost
    mins[y][x] = cost

    dx = [0, 0, -1, 1]
    dy = [-1, 1, 0, 0]
    0.upto(3){|i|
      nx = x + dx[i]
      ny = y + dy[i]

      next if nx < 0 || nx >= SIZE || ny < 0 || ny >= SIZE

      ncost = cost + map[ny][nx]

      next if mins[ny][nx] >= 0 && mins[ny][nx] <= ncost

      queue.push([nx, ny, ncost])
    }
  end

  mins[SIZE-1][SIZE-1]
end

def make(a1, a2)
  ret = []
  0.upto(SIZE-1){|i|
    row = []
    0.upto(SIZE-1){|j|
      row << a1[j] + a2[i]
    }
    ret << row
  }
  ret
end

map = make([8, 6, 8, 9, 3, 4, 1, 7, 6, 1], [5, 1, 1, 9, 1, 6, 9, 0, 9, 6])

puts solve(map)
