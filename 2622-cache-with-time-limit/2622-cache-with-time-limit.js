var TimeLimitedCache = function() {
    
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
    
};

/** 
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function(key) {
    
};

/** 
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function() {
    
};

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */
 var TimeLimitedCache = function () {
    this.cache = new Map();
};

TimeLimitedCache.prototype.set = function (key, value, duration) {
    const now = Date.now();
    const exists =
        this.cache.has(key) && this.cache.get(key).expire > now;

    this.cache.set(key, {
        value: value,
        expire: now + duration
    });

    return exists;
};

TimeLimitedCache.prototype.get = function (key) {
    const now = Date.now();

    if (!this.cache.has(key)) return -1;

    const entry = this.cache.get(key);
    if (entry.expire <= now) return -1;

    return entry.value;
};

TimeLimitedCache.prototype.count = function () {
    const now = Date.now();
    let count = 0;

    for (const entry of this.cache.values()) {
        if (entry.expire > now) count++;
    }

    return count;
};