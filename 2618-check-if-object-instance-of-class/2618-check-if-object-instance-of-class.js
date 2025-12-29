/**
 * @param {*} obj
 * @param {*} classFunction
 * @return {boolean}
 */
var checkIfInstanceOf = function(obj, classFunction) {
    if (obj == null || classFunction == null) return false;

    // Handle primitive values (Number, String, Boolean)
    if (typeof obj !== "object") {
        obj = Object(obj);
    }

    let proto = Object.getPrototypeOf(obj);
    const targetProto = classFunction.prototype;

    while (proto !== null) {
        if (proto === targetProto) return true;
        proto = Object.getPrototypeOf(proto);
    }

    return false;
};

/**
 * checkIfInstanceOf(new Date(), Date); // true
 */