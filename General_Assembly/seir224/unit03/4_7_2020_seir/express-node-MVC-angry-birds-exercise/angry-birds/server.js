const express = require("express");
const app = express();
const birds = require("./data/angry-birds-data")

const logger = require('morgan');
app.use(logger('dev'));

app.get('/', (req, res) => {
    res.send('hitting default route on repl server');
});

const birdsRouter = require('./routes/birdsRouter');
app.use('/angry-birds', birdsRouter);

app.listen(3000, () => {
    console.log("listening on port 3000");
});