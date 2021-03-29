let m = new Map();
function comb(N, n, str, now, idx) {
    if (n > N) {
     	let cnt = m.get(now);
        if (cnt != undefined) 
            m.set(now, cnt+1);
        else
            m.set(now, 1);
        return;
    }
    for (let i = idx; i < str.length; i++) {
        comb(N, n+1, str, now+str[i], i+1);
    }
}
function solution(orders, course) {
    var answer = [];
    for (let o of orders) {
        o = o.split('').sort().join('');
        for (let c of course) {
            comb(c, 1, o, "", 0);
        }
    }
    for (let c of course) {
        let tmp = Array.from(m).filter(it => it[0].length == c);
        if (tmp.length == 0)
            continue;
        tmp.sort((a, b) => a[1] - b[1]);
        let max = tmp.pop();
        if (max[1] < 2)
            continue;
        answer.push(max[0]);
        while (tmp.length > 0 && tmp[tmp.length-1][1] == max[1]) {
            max = tmp.pop();
            answer.push(max[0]);
        }
    }
    return answer.sort();
}
// console.log(solution(["ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"], [2,3,4]))
console.log(solution(["ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"], [2,3,5]));
// console.log(solution(["XYZ", "XWY", "WXA"], [2,3,4]))