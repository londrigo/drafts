const http = require('http');

// const hostname = '127.0.0.1'; // "localhost"
// const hostname = '0.0.0.0'; // bind na placa de rede
const hostname = '::'; // bind ipv4 e ipv6 para fora

const port = 3000;

const prepareResponse = (_, res) => {
    res.statusCode = 200;
    res.setHeader('Content-Type', 'text/html');
    res.end('<h1>Hello World</h1>');
}

const server = http.createServer(prepareResponse);

server.listen(port, hostname, () => {
    console.log(`Server running at http://${hostname}:${port}`);
})