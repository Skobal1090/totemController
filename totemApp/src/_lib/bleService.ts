export async function scanDevices() : Promise<string[]>{

    var devices : string[] = [];

    devices.push("device 1");
    devices.push("device 2");
    devices.push("weeeeeee");
    devices.push("woohoohooo");

    return new Promise(resolve => {
        setTimeout(() => {
            resolve(devices);
        }, 1000);
    });
}