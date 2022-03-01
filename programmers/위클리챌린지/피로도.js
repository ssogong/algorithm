function solution(k, dungeons) {
    let answer = 0;
    const N = dungeons.length;
    let visited = new Array(N).fill(0);
    const DFS = (depth, nowK) => {
        if (depth > answer)
            answer = depth;
        for (let i = 0; i < N; i++) {
            if (visited[i] || nowK < dungeons[i][0] || nowK < dungeons[i][1])
                continue;
            visited[i] = 1;
            DFS(depth+1, nowK - dungeons[i][1]);
            visited[i] = 0;
        }
    }
    DFS(0, k);
    return answer;
}