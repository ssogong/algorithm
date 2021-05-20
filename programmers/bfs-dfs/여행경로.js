let m = new Map();
let visited = [];
let answer = [];
function DFS(now, tickets) {
    if (answer.length == tickets.length+1)
        return true;
    if (!m.has(now))
        return false;
    let targets = m.get(now);
    for (let t of targets) {
        let idx = tickets.findIndex((ticket, i) => !visited[i] && ticket[0] == now && ticket[1] == t);
        if (idx == -1)
          continue;
        visited[idx] = 1;
        answer.push(t);
        if (DFS(t, tickets))
            return true;
        visited[idx] = 0;
        answer.pop(t);
    }
    return false;
}
function solution(tickets) {
    for (let t of tickets) {
        visited.push(0);
    	if (!m.has(t[0]))
            m.set(t[0], [t[1]]);
        else {
            let tmp = m.get(t[0]);
            tmp.push(t[1]);
            tmp.sort();
        }
    }
    answer.push('ICN');
    DFS('ICN', tickets)
    return answer;
}

// console.log(solution([["ICN", "JFK"], ["HND", "IAD"], ["JFK", "HND"]], 	["ICN", "JFK", "HND", "IAD"]));
console.log(solution([["ICN","A"],["ICN","A"],["A","ICN"]]));