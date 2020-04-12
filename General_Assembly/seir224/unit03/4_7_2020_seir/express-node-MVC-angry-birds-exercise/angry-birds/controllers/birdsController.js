// Controller
//  - business logic
//  - has direct access to the data (Model)
// const quotes = require('../data/quotes')
const birdsModel = require('../models/birdsModel');

const getAll = (req, res) => {
    const birds = birdsModel.getAll()
    res.status(200).json({
      status:'ok',
      birds
    })
}

const getById = (req, res) => {
  const id = req.params.id
  const bird = birdsModel.getById(id)

  if(bird.length) {
    res.json({
      status:'ok',
      bird: bird[0]
    });
  } 
  else {
    res.json({
      status: 401,
      msg: 'Bird not found'
    });
  }
}

module.exports = {
  getAll,
  getById
}