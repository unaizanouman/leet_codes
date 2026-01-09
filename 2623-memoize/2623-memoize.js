function memoize(fn) {
    const cache = new Map();
    let callCount = 0;

    return function (...args) {
        const key = JSON.stringify(args);

        if (!cache.has(key)) {
            callCount++;
            cache.set(key, fn(...args));
        }

        return cache.get(key);
    };
}