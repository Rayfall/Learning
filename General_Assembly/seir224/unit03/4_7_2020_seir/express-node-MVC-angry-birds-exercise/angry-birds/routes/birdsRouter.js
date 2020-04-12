const { Router } = require('express')
const router = Router()
const birds = require('../data/angry-birds-data')
const birdsController = require('../controllers/birdsController')

router.get('/', birdsController.getAll);
router.get('/:id', birdsController.getById);

module.exports = router;