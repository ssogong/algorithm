function solution(sizes) {
    let max_width = max_height = -Infinity;
    for (let s of sizes) {
        if (s[0] > s[1])
            s = [s[1], s[0]];
        max_width = Math.max(s[0], max_width);
        max_height = Math.max(s[1], max_height);
    }
    return max_width * max_height;
}