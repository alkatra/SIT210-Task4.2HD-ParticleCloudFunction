async function handleEvent(param) {
    
    await fetch('https://api.particle.io/v1/devices/e00fce687734db920f1c69e8/returnValue', {
    method: 'POST',
    headers:{
      'Content-Type': 'application/x-www-form-urlencoded'
    },    
    body: new URLSearchParams({
        'access_token': 'ab204503b48cf34aa74b7582ce80d1700497e0b3',
        'args': param
    })
});
    
}