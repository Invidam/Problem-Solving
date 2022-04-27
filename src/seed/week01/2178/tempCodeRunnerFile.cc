< 0 || yoff > M) || visited[xoff][yoff])
                continue;
            q.push(p(xoff, yoff));
            visited[xoff][yoff] = true;