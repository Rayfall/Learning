const birds = require('../data/angry-birds-data')

const getAll = () => {
    return birds
}

const getById = (id) => {
  const bird = birds.birds.filter( bird => {
    return bird.id == id
  });

  if(bird.length) {
    return bird
  } 
  else {
    return []
  }
}

module.exports = {
  getAll,
  getById
}