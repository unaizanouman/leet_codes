var maximizeSquareHoleArea = function(n, m, hBars, vBars) {
    function maxGap(bars) {
        bars.sort((a, b) => a - b);
        let maxLen = 1;
        let curr = 1;

        for (let i = 1; i < bars.length; i++) {
            if (bars[i] === bars[i - 1] + 1) {
                curr++;
            } else {
                curr = 1;
            }
            maxLen = Math.max(maxLen, curr);
        }
        return maxLen + 1; // gap size
    }

    const hGap = maxGap(hBars);
    const vGap = maxGap(vBars);

    const side = Math.min(hGap, vGap);
    return side * side;
};