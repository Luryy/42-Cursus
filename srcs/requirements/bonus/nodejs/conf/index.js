const express = require('express');
const mariadb = require('mariadb');
const https = require('https');
const axios = require('axios');
const path = require('path');

const app = express();
const pool = mariadb.createPool({
	host: process.env.MY_HOST_SQL,
	user: process.env.MYSQL_USER,
	database: process.env.MYSQL_DATABASE,
	password: process.env.MYSQL_PASSWORD,
	connectionLimit: 5
});

app.listen(3000);

app.get('/nodejs', async (req, res) => {
	const mariadb = await getMariadbStatus();
	const wordpress = await getWordpressStatus();

	res.json({
		mariadb,
		wordpress
	})
})

app.get('/nodejs/resume', async (req, res) => {
	const root = path.dirname(require.main.filename)
	const filePath = './site/resume.html';
	const file = path.join(root, filePath)
	res.sendFile(file)
})

app.get('/nodejs/resume.css', async (req, res) => {
	const root = path.dirname(require.main.filename)
	const filePath = './site/resume.css';
	const file = path.join(root, filePath)
	res.sendFile(file)
})


async function getMariadbStatus() {
	try {
		const conn = await pool.getConnection()
		conn.release()
		return true
	} catch {
		return false
	}
}

const agent = new https.Agent({
  rejectUnauthorized: false
});

async function getWordpressStatus() {
	try {
		await axios.get('https://nginx', { httpsAgent: agent })
		return true
	} catch {
		return false
	}
}